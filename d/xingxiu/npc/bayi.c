// npc: /d/xingxiu/npc/bayi.c
// Jay 3/25/96

inherit NPC;
void create()
{
	set_name("巴依", ({ "bayi"}));
	set("gender", "男性");
	set("age", 55);

	set_skill("unarmed", 30);
	set_skill("dodge", 30);
	set_skill("parry", 30);
	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	set_temp("apply/damage", 10);
	set("attitude","heroism");
	set("inquiry", ([
		"金子"   : "我照着阿凡提的办法种了好多金子，可什么也没长出来，连种子也没了。",
		"阿凡提" : "我把他关到我的客厅里了。",
	]) );

	set("combat_exp", 25000);
	set("shen_type", -1);
	setup();
	set("chat_chance", 10);
	set("chat_msg", ({
		"巴依嘟嘟囔囔：沙子一筐子金子一屋子，金子一筐子沙子一屋子。\n",
		"巴依冲着你大喊：你站在我的树荫里得付我钱！\n",
		"巴依叹了口气：我们对着沙漠喊：金子，你在哪里？\n",
	}) );
	carry_object(__DIR__"obj/wcloth")->wear();
}
