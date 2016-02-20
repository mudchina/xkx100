//NPC /d/city/npc/geji.c
#include <ansi.h>
inherit NPC;
void create()
{
	set_name("歌妓", ({ "ge ji", "ji" }));
	set("long", "她是扬州里的著名的歌妓，卖艺不卖身。\n");
	set("gender", "女性");
	set("age", 17);
	set("attitude", "friendly");
	set("shen_type", 1);

	set("per", 27);
	set("str", 15);
	set("int", 14);
	set("con", 15);
	set("dex", 16);
	set("qi", 100);
	set("max_qi", 100);
	set("jing", 100);
	set("max_jing", 100);
	set("neili", 10);
	set("max_neili", 10);
	set("combat_exp", 500);

	set_skill("unarmed", 10);
	set_skill("dodge", 10);
	set_skill("parry", 10);

	set("chat_chance", 10);
	set("chat_msg", ({
		"歌妓宛转唱道：
“青山隐隐水迢迢，秋尽江南草木凋。二十四桥明月夜，玉人何处教吹箫？”\n",
		"歌妓轻声低唱：
“落魄江南载酒行，楚腰纤细掌中轻。十年一觉扬州梦，赢得青楼薄幸名。”\n",
		"歌妓幽幽浅唱：
“星分牛斗，疆连淮海，扬州万井提封。花发路香，莺啼人起，朱帘十里春风。
豪杰气如虹。曳照春金紫，飞盖相从。巷入垂杨，画桥南北翠烟中。”\n",
		"歌妓幽幽浅唱：
“淮山浮远翠，淮水漾深绿。倒影入楼台，满栏花扑扑。谁知寰闺外，依旧
有芦屋。时见淡妆人，青裙曳长幅。”\n",
		(: random_move :)
	}) );

	setup();
	carry_object(CLOTH_DIR+"cloth/qi-dress")->wear();
}
