
inherit NPC;
#include <ansi.h>

void create()
{
	set_name("仆人", ({ "pu ren", "puren","ren" }) );
	set("gender", "男性" );
	set("age", 25);
	set("int", 28);
	set("long","这是个仆人打扮的年青人，两眼乱转，四处看个不停,好象害怕什么。\n");
	set("attitude", "peaceful");
	set("combat_exp",10000+random(5000));
	set("chat_chance", 3);
	set("chat_msg", ({
		"仆人突然说道: 后院很需要人手，老爷正为此烦恼呢。\n",
		"仆役低声的说: 在后院做事有好多好处啊。\n",
	}));
	set("inquiry", ([
		"做事" : "你去找老爷子吧！\n",
		"工作" : "你去找老爷子吧？\n",
		"好处" : "我可不想告诉你.\n",
	]) );
	setup();
	carry_object("/clone/misc/cloth")->wear();
}
