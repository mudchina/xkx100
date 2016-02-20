//shendiao.c

inherit NPC;

void create()
{
	set_name("海燕", ({ "hai yan", "yan" }) );
	set("race", "飞禽");
	set("age", 20);
	set("long", "一只翱翔于海天之间的海燕。\n");
	set("attitude", "peaceful");
	set("chat_chance", 1);
	set("chat_msg", ({
		"海燕在惊涛骇浪间翱翔着……\n",
		"海燕激情地歌唱着……\n",
	}));
        set("qi", 400);
	set("max_qi", 400);
	set("jing", 200);
	set("max_jing", 200);
	set("str", 20);
	set("cor", 20);
	set("combat_exp", 2000);
	setup();
}


