[%bs.raw {|require('./App.css')|}];

[@bs.module] external logo : string = "./logo.svg";

type user = {
  first_name: string,
  last_name: string
};

type usersApiResponse = {payload: list(user)};

type state =
  | Loading
  | Error
  | Loaded(list(user));

type actions =
  | UsersFetch
  | UsersFailedToFetch
  | UsersFetched(list(user));

module Decode = {
  let userItem = json =>
    Json.Decode.{
      first_name: json |> field("first_name", string),
      last_name: json |> field("last_name", string)
    };
  let users = json =>
    Json.Decode.{payload: json |> field("payload", list(userItem))};
};

let component = ReasonReact.reducerComponent("App");

let reducer = (action, _state) =>
  switch action {
  | UsersFetch =>
    ReasonReact.UpdateWithSideEffects(
      Loading,
      (
        self =>
          Js.Promise.(
            Fetch.fetch("http://0.0.0.0:4000/api/users")
            |> then_(Fetch.Response.json)
            |> then_(json =>
                 json
                 /* |> Json.parseOrRaise */
                 |> Decode.users
                 |> (users => self.send(UsersFetched(users.payload)))
                 |> resolve
               )
            |> catch(_err => {
                 Js.log(_err);
                 Js.Promise.resolve(self.send(UsersFailedToFetch));
               })
            |> ignore
          )
      )
    )
  | UsersFetched(users) => ReasonReact.Update(Loaded(users))
  | UsersFailedToFetch => ReasonReact.Update(Error)
  };

module User = {
  let component = ReasonReact.statelessComponent("User");
  let make = (~userState, _children) => {
    ...component,
    render: _self =>
      switch userState {
      | Error => <div> (ReasonReact.string("An error occurred!")) </div>
      | Loading => <div> (ReasonReact.string("Loading...")) </div>
      | Loaded(users) =>
        <div>
          <h1> (ReasonReact.string("Users")) </h1>
          (
            ReasonReact.arrayToElement(
              Array.of_list(
                List.map(
                  user =>
                    <p>
                      (
                        ReasonReact.string(
                          user.first_name ++ " " ++ user.last_name
                        )
                      )
                    </p>,
                  users
                )
              )
            )
          )
        </div>
      }
  };
};

let make = _children => {
  ...component,
  initialState: _state => Loading,
  reducer,
  didMount: self => self.send(UsersFetch),
  render: self =>
    <div className="App">
      <div className="App-header">
        <img src=logo className="App-logo" alt="logo" />
        <h2> (ReasonReact.string("Welcome to Princess")) </h2>
      </div>
      <p className="App-intro">
        (
          ReasonReact.string(
            "Frontend is Reason and React, backend is Elixir and Phoenix"
          )
        )
      </p>
      <User userState=self.state />
    </div>
};
