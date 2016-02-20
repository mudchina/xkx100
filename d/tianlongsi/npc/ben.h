// ben.h for fight

void init()
{
	::init();

	if (interactive(this_player()) && this_player()->query_temp("fighting"))
	{
		COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon") );
		this_player()->add_temp("beat_count", 1);
	}
}
void attempt_apprentice(object ob)
{
        if ((int)ob->query_skill("kurong-changong", 1) < 110) {
                command("say 你内功修为还不到火候，进天龙寺也是徒劳。\n");
                return;
        }
	command("say 好吧，老衲就收下你这个俗家弟子了。");
	command("recruit " + ob->query("id"));
}

