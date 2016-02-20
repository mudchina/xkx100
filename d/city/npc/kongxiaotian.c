//Npc : kongxiaotian.c 孔小天

inherit NPC;
#include "kid.h"

void create()
{
	set_name("孔小天",({ "kong xiaotian", "xiao hai", "kid"}) );
	set("title", "学童");
	set("gender", "男性" );
	set("age", 13);
	set("long", "这是个一个资政书院的学童，正在和同伴玩耍。\n");
	set("combat_exp", 3);
    set("positive_score", 10);
	set("str", 12);
	set("con", 18);
	set("dex", 20);
	set("per", 24);
	set("chat_chance", 3);
	set("chat_msg", ({
		"孔小天道：我们老大居然喜欢上了顾月儿了，真是奇怪了！\n",
        "孔小天道：想不想我告诉你一个秘密呢？\n",
        "孔小天道：我们的老师也挺可怜的，唉～～～～！\n"
    }));
    set("inquiry", ([
        "秘密" : (: ask_secret :),
        "secret" : "我不懂洋文的。\n",
    ]));
    set("papa_name", "孔万擎" );
	set("attitude", "peaceful");
	setup();
	carry_object(__DIR__"obj/xiaogua")->wear();
}
