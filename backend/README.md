# Backend

## Installation

Follow the Phoenix installation guide: https://hexdocs.pm/phoenix/installation.html

Install postgresql and set up database:

```
brew install postgresql
createuser admin --createdb
createdb backend_dev -U admin
```

## Starting Phoenix server

To start your Phoenix server:

* Install dependencies with `mix deps.get`
* Create and migrate your database with `mix ecto.create && mix ecto.migrate`
* Install Node.js dependencies with `cd assets && npm install`
* Start Phoenix endpoint with `mix phx.server`

Now you can visit [`localhost:4000`](http://localhost:4000) from your browser.

Ready to run in production? Please [check our deployment guides](http://www.phoenixframework.org/docs/deployment).

## Populating user database

In your terminal of choice go into the Elixir console using `iex -S mix`. Then run

```
iex(1)> alias Backend.{Repo, User}
iex(2)> Repo.insert(%User{first_name: "Name", last_name: "Surname"})
```

## Learn more

* Official website: http://www.phoenixframework.org/
* Guides: http://phoenixframework.org/docs/overview
* Docs: https://hexdocs.pm/phoenix
* Mailing list: http://groups.google.com/group/phoenix-talk
* Source: https://github.com/phoenixframework/phoenix
