defmodule PrincessApi.UserController do
  use BackendWeb, :controller

  def index(conn, _params) do
    users = [
      %{first_name: "Alexander",
        last_name: "Keliris"},
      %{first_name: "Anicka",
        last_name: "Doubkova"},
    ]
    json conn, users
  end
end
