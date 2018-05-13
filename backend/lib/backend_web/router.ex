defmodule BackendWeb.Router do
  use BackendWeb, :router

  pipeline :api do
    plug CORSPlug, origin: "http://localhost:3000"
    plug :accepts, ["json"]
  end

  scope "/api", Backend do
    pipe_through :api

    resources "/users", UserController
  end
end
