//Npc : lixiaoqi.c 李小琪

inherit NPC;
#include "kid.h"

void create()
{
	set_name("李小琪",({ "li xiaoqi", "xiao hai", "kid"}) );
	set("title", "学童");
	set("gender", "男性" );
	set("age", 12);
	set("long", "这是个一个资政书院的学童，正在和同伴玩耍。\n");
	set("combat_exp", 4);
     set("positive_score", 10);
	set("str", 11);
	set("con", 18);
	set("chat_chance", 3);
	set("chat_msg", ({
		"李小琪道：我们老大居然喜欢上了顾月儿了，真是奇怪了！\n",
        "李小琪道：想不想我告诉你一个秘密呢？\n",
        "李小琪道：我们的老师是个笨蛋！！！！\n"
    }));
    set("inquiry", ([
        "秘密" : (: ask_secret :),
        "secret" : "我不懂洋文的。\n",
    ]));
    set("papa_name", "李千叶" );
	set("cps", 20);
	set("per", 24);
	set("attitude", "peaceful");
	setup();
	carry_object(__DIR__"obj/xiaogua")->wear();
}
