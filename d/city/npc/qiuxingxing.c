// qiuxingxing.c

inherit NPC;
#include "kid.h"
void create()
{
	set_name("仇星星",({ "qiu xingxing", "xiao hai","kid"}) );
	set("title", "学童");
	set("gender", "男性" );
	set("age", 11);
	set("long", "这是个一个资政书院的学童，正在和同伴玩耍。\n");
	set("combat_exp", 3);
    set("positive_score", 10);
	set("shen_type", 1);
	set("str", 10);
	set("cor", 16);
	set("cps", 20);
	set("per", 23);
	set("chat_chance", 3);
	set("chat_msg", ({
        "仇星星道：我们老大喜欢上了顾月儿了，唉～～～～～！\n",
        "仇星星道：想不想我告诉你一个秘密呢？\n",
        "仇星星道：我们的老师是个笨蛋！！！！\n"
    }));
    set("inquiry", ([
        "秘密" : (: ask_secret :),
        "secret" : "我不懂洋文的。\n",
    ]));
    set("papa_name", "仇好石" );
	set("attitude", "peaceful");
	setup();
	carry_object(__DIR__"obj/xiaogua")->wear();

}
