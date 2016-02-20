// wang.c
inherit NPC;
#include <ansi.h>

void create()
{
	set_name("王语嫣", ({ "wang yuyan","wang","yuyan" }) );
	set("gender", "女性" );
	set("title", HIM"蔓陀山庄小姐"NOR );
	set("age", 16);
	set("long", 
"王语嫣秀美的面庞之上，端庄中带有稚气，隐隐含着一丝忧色。
见你注目看她不觉低头轻叹。只听得这轻轻一声叹息。霎时之间，
你不由得全身一震，一颗心怦怦跳动，心想：“这一声叹息如此
好听，世上怎能有这样的声音？”听得她唇吐玉音，更是全身热
血如沸！
待见到她左手食指如一根葱管，点在右手雪白娇嫩的手背之上，
突觉喉头干燥，头脑中一阵晕眩，忍不住没话找话问道：“姑……
姑娘，你叫什么名字？”\n");
	set("shen_type", 1);
	set("combat_exp", 1000000);
	set("per", 30);
	set("str", 20);
	set("dex", 18);
	set("con", 19);
	set("int", 20);
	set("attitude", "friendly");
	set("max_qi", 1000);
	set("max_jing", 800);
	set("neili", 100);
	set("max_neili", 100);
	set("score", 800);

	set_skill("force", 10);
	set_skill("dodge", 100);
	set_skill("lingboweibu", 100);
	set_skill("unarmed", 10);
	set_skill("sword", 10);
	set_skill("parry", 10);
	map_skill("dodge", "lingboweibu");
	set("inquiry",([
		"曼陀山庄" : "这里就是曼陀山庄。\n",
		"琅缳玉洞" : "玉洞在潮声洞的一个支洞里，你的武功有点基础了就可以去那里找了。\n",
		"还施水阁" : "光复大燕就那么重要么？\n",
		"王语嫣"   : "你也知道我的名字？\n",
		"南慕容"   : "表哥和丐帮乔帮主齐名，合称“南慕容北乔峰”！\n",
		"慕容复"   : "你、你有我表哥的消息么？\n",
		"王夫人"   : "就是公子爷的舅妈，曼陀山庄的庄主！\n",
		"阿朱"     : "那小妮子只大我一岁，整天就喜欢扮别人玩。\n",
		"阿碧"     : "那小妮子只大我一岁，整天就喜欢扮别人玩。\n",
		"邓百川"   : "你问邓大哥啊？他在他青风庄上呢。\n",
		"公冶乾"   : "公冶二哥把信鸽传书一编码，就没几个人读得懂了。\n",
		"包不同"   : "包三哥最爱抬杠了，你见了他还是闭嘴的好。\n",
		"风波恶"   : "风四哥最是豪爽了，他从不与人计较什么。\n",
	]) );
	setup();
	carry_object(__DIR__"obj/ou_cloth")->wear();
}
