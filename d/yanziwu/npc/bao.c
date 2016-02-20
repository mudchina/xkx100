// bao.c
inherit NPC;
#include <ansi.h>

void create()
{
	set_name("包不靓", ({ "bao buliang","bao","buliang" }) );
	set("gender", "女性" );
	set("age", 6);
	set("long",
"她年方六岁，眼睛一大一小，鼻孔朝天，耳朵招风，包三先生有何吩
咐，此人决计不听，叫她哭必笑，叫她笑必哭，哭起来两个时辰不停，
乃是包三先生的宝贝女儿包不靓。\n");
	set("shen_type", 1);
	set("combat_exp", 100);
	set("str", 20);
	set("dex", 18);
	set("con", 19);
	set("int", 20);
	set("attitude", "friendly");
	create_family("姑苏慕容", 34, "弟子");
	setup();
	carry_object("/clone/misc/cloth")->wear();
}
