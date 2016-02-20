// Obj: /d/nanshaolin/obj/chan.h
// Last Modified by winder on May. 29 2001
void init()
{
	::init();

	if (interactive(this_player()) &&
		this_player()->query_temp("fighting") &&
		living(this_player()))
	{
		COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon"), 1);
		this_player()->add_temp("beat_count", 1);
	}
}
