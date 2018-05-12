defmodule BackendWeb.Router do
  use BackendWeb, :router

  pipeline :api do
    plug :accepts, ["json"]
  end

  scope "/api", Backend do
    pipe_through :api

    resources "/users", UserController
  end
end
