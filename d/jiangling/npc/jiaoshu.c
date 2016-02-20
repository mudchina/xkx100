//Edited by fandog, 02/13/2000

inherit NPC;

void create ()
{
	set_name("教书先生", ({"jiao shu", "teacher"}));
	set("long", "他摇头晃脑的，拿了一张纸，一只墨盒，一枝笔，正抄写着什么。\n");
	set("gender", "男性");
	set("age", 24);
	set("combat_exp", 1000);
	set("str", 24);
	set("int", 15);
	set("dex", 18);
	set("con", 22);
	set("per", 20);
	set("chat_msg", ({
	"教书先生眯缝着眼，仔细端详着城墙上用石灰泥写的数目字。\n",
	"教书先生拿了一张纸，一只墨盒，一枝笔，摇头晃脑的，将城墙上那几行字抄了下来。。\n",
	"教书先生神秘兮兮道：“老夫这么做自有用处，旁人不得问之也。”\n",
	(: random_move :)
	}) );

  
	setup();
	carry_object("/clone/cloth/cloth")->wear();
}


