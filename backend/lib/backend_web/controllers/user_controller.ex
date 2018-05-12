defmodule Backend.UserController do
  use BackendWeb, :controller

  def index(conn, _params) do
    users = [
      %Backend.User{first_name: "Alexander",
                        last_name: "Keliris"},
      %Backend.User{first_name: "Anicka",
                        last_name: "Doubkova"},
    ]
    json conn, users
  end
end
