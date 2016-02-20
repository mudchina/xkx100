// Last Modified by winder on Nov. 17 2000

inherit NPC;

int ask_location();
string ask_name();
string ask_rumors();
string ask_thd();

void create()
{
	set_name("艄公", ({ "gong", "shaogong" }) );
	set("gender", "男性" );
	set("age", 50);
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("rank_info/respect", "老船家");
	set("inquiry", ([
		"name": (: ask_name :),
		"rumors": (: ask_rumors :),
		"here": "这里叫做东海，传说四海龙王里的东海王就住在水底。",
		"位置": (: ask_location :),
		"taohuadao": (: ask_thd :),
		"桃花岛": (: ask_thd :),
		"weizhi": (: ask_location :),
		"走": "您得告诉我往哪边开呀(turn n|w|s|e)！",
		"出海": "您得告诉我往哪边开呀(turn n|w|s|e)！",
		"开船": "您得告诉我往哪边开呀(turn n|w|s|e)！",
		"起航": "您得告诉我往哪边开呀(turn n|w|s|e)！",
		"启航": "您得告诉我往哪边开呀(turn n|w|s|e)！",
	]) );
	setup();
}

int ask_location()
{
	object ob=this_player();

	say("艄公看了看海图，说道：我们现在的位置是(" + ob->query_temp("thd_locx") + "," + ob->query_temp("thd_locy") + ")。\n");
	return 1;
}

string ask_name()
{
	object ob=this_player();

	if (ob->query_temp("thd_target") == "thd")
		return "不敢不敢，老汉名唤陈阿生，已经在这里划了三十多年船了。\n";
	if (ob->query_temp("thd_target") == "bay")
		return "老汉只不过是黄岛主的属下而已，哪有什么名字。\n";
}

string ask_rumors()
{
	object ob=this_player();

	if (ob->query_temp("thd_target") == "thd")
		return "听说桃花岛上住着一个恶魔，唉，要不是为了这每趟五两银子的辛苦费，\n老汉是说什么也不会去的。\n";
	if (ob->query_temp("thd_target") == "bay")
		return "老汉长居桃花岛，没听说过什么流言。\n";
}

string ask_thd()
{
	object ob=this_player();

	if (ob->query_temp("thd_target") == "thd")
		return "听说桃花岛上住着一个恶魔，唉，要不是为了这每趟20两银子的辛苦费，\n老汉是说什么也不会去的。\n";
	if (ob->query_temp("thd_target") == "bay")
		return "老汉长居桃花岛，黄岛主待我们很好。\n";
}
