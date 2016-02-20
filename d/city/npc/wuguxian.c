// wuguxian.c

#include <ansi.h>
inherit NPC;

void create()
{
	set_name(YEL "吴古贤" NOR,({ "wu guxian", "wu", "teacher"}) );
	set("title", "资政书院先生");
	set("gender", "男性" );
	set("age", 55);
	set("long", @LONG
吴古贤据说在资政学院已经教了十几年的书，年纪也大了，变的越来越
迂腐，学问和年轻时差的远了；又当今的大儒增先生开始授课，吴先生
的资政学院几乎成了一些顽劣儿童的乐园。
LONG
	);
	set("attitude", "peaceful");
	set("combat_exp", 10);
	set("str", 15);
	set("con", 18);
	set("dex", 20);
	set("per", 21);
	set_skill("literate", 60);
	set("chat_chance", 3);
	set("chat_msg", ({
		"吴古贤叹道：现在的孩子呀，唉！！！！！\n",
		"吴古贤道：老朽已经不中用了，该回老家过过清闲日子了。",
		"吴古贤叹道：教几十年的书，学问却越来越差了，唉。。。。",
	}));
	set("inquiry", ([
		 "戒尺" : "戒尺，这把戒尺我已有十数年未用了。说完，吴古贤长叹一声。",
	]));
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

