// wang.c

#include <ansi.h>

inherit NPC;
void create()
{
	set_name("王元霸", ({ "wang yuanba", "wang", "yuanba" }) );
	set("title", HIY"金刀门"NOR"第三代门主");
	set("nickname", HIG"中州大侠"HIY"金刀无敌"NOR);
	set("gender", "男性" );
	set("shen_type", 1);
	set("age", 70);
	set("str", 25);
	set("con", 25);
	set("dex", 25);
	set("int", 25);
	set("long",
"王元霸已有七十来岁，满面红光，颚下一丛长长的白须飘在胸前，精神
矍铄，左手呛啷啷的玩着两枚鹅蛋大小的金胆。武林中人手玩铁胆，甚
是寻常，但均是镔铁或纯钢所铸，王元霸手中所握的却是两枚黄澄澄的
金胆，比之铁胆固重了一倍有余，而且大显华贵之气。\n" );
	set("combat_exp", 500000);
	set("attitude", "friendly");
	set_skill("blade", 100);
	set_skill("dodge", 100);
	set_skill("unarmed", 100);
	set_skill("throwing", 100);
	set_skill("feixing-shu", 100);
	set_skill("yanfly", 100);
	set_skill("parry", 100);
	map_skill("throwing", "feixing-shu");
	map_skill("parry", "feixing-shu");
	map_skill("dodge", "yanfly");

	setup();
	carry_object(__DIR__"obj/jindan")->wield();
	carry_object(CLOTH_DIR"jinduan")->wear();
	add_money("gold", 5);
}

