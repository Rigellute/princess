defmodule Backend.User do
  use Ecto.Schema
  alias Backend.User

  schema "users" do
    field :first_name, :string
    field :last_name, :string

    timestamps()
  end
end
