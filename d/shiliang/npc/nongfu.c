// Feb. 6, 1999 by Winder
inherit NPC;
void create()
{
	set_name("农夫", ({ "nong fu","nong","fu"}) );
	set("gender", "男性" );
	set("age", 24+random(10));
	set("long", "这是一个山间农夫，十分粗俗。\n");
	set("shen_type", 1);
	set("combat_exp", 4000);
	set("str", 18);
	set("dex", 18);
	set("con", 18);
	set("int", 19);
	set("attitude", "friendly");
        set("chat_msg", ({
        "农夫呸了一口，说道：温家没个好东西！活该女儿被糟蹋。\n",
        "农夫咬牙切齿地说道：温家横行霸道，不会有好报！\n"
        }));
	setup();
	carry_object("/clone/misc/cloth")->wear();
}
