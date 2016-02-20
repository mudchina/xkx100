inherit __DIR__"m_weapon";

init()
{
  seteuid(getuid());
  new(__DIR__"m_weapon")->move(this_player());
  call_out("destob",0);
}
void destob()
{
  destruct(this_object());
}