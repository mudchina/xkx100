// ahda.c

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("蜥蜴", ({ "xiyi" }));
	set("title", "民间工艺品店店主");
	set("shen_type", 1);

	set("gender", "男性" );
	set("long", @LONG
店主是一个文弱书生，他正轻摇折扇，冲你点头微笑。
LONG);
	set("nickname", HIY"爱在蜥元前"NOR);
	set("age", 25);
	set("per", 30);
	set("attitude", "friendly");		
        set("no_get", "1");
	set("env/no_teach", "1");

	set("inquiry", ([
	]));                 

	setup();

        carry_object(__DIR__"obj/pen")->wield();
	carry_object(CLOTH_DIR"male-cloth")->wear();
        carry_object(CLOTH_DIR"male-shoe")->wear();
}