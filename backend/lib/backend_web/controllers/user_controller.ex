defmodule Backend.UserController do
  use BackendWeb, :controller

  def index(conn, _params) do
    users = Backend.Repo.all(Backend.User)
    json conn, %{ payload: users }
  end
end
