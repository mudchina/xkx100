// yangleishi.c

inherit NPC;

#include "kid.h"

void create()
{
	set_name("杨磊石",({ "yang leishi", "xiao hai", "kid"}) );
	set("title", "学童");
	set("gender", "男性" );
	set("age", 12);
	set("long", "这是个一个资政书院的学童，正在和同伴玩耍。\n");
	set("combat_exp", 4);
	set("chat_chance", 3);
	set("chat_msg", ({
		"杨磊石道：我最喜欢顾月儿了，长大了一定要娶她为妻。\n",
		"杨磊石道：想不想我告诉你一个秘密呢？\n",
		"杨磊石道：在所有的学童中我是老大！！！\n"
	}));
	set("inquiry", ([
		"秘密" : (: ask_secret :),
		"secret" : "我不懂洋文的。\n",
	]));
	set("str", 11);
	set("cor", 18);
	set("cps", 20);
	set("per", 24);
	set("papa_name", "杨万萧" );
	set("attitude", "peaceful");
	setup();
	carry_object(__DIR__"obj/xiaogua")->wear();
}

