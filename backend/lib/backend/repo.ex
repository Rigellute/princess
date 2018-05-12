defmodule Backend.Repo do
  # use Ecto.Repo, otp_app: :backend

  def start_link do
    {:ok, self()}
  end

  def all(Backend.User) do
    [
      %Backend.User{first_name: "Alexander",
                        last_name: "Keliris"},
      %Backend.User{first_name: "Anicka",
                        last_name: "Doubkova"},
    ]
  end

end
