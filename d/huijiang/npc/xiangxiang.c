// Room: /d/honghua/npc/xiangxiang.c
// Last Modified by winder on Sep. 12 2001

inherit NPC;
void create()
{
	set_name("香香公主",({"xiangxiang gongzhu", "gongzhu"}));
	set("gender","女性");
	set("long","木卓伦的小女儿，自幼体有异香。\n");
	set("combat_exp",40000);
	set("age",17);
	set("per", 40);

	setup();
	add_money("silver",20);
	carry_object("/clone/cloth/luoyi")->wear();
}
