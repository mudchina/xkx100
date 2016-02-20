// shandong3.c
// Modified by Java Apr.27 1998

inherit ROOM;
void create()
{
	set("short","山洞");
	set("long",@LONG
这是一个小小的山洞，血刀老祖的藏身之地。由於此地比较隐秘，
仇家很难寻到这来。洞底有一张供桌，上面供了什麽东西，你看不清。
壁上画了一些模糊不清的文字图案，也不知道是些什么。
LONG );
	set("exits",([
		"out" : __DIR__"shandong2",
	]));
	set("objects", ([
		CLASS_D("xueshan")+"/xuedao" :1,
		__DIR__"npc/x_lama" :1,
	]));
	set("valid_startroom","1");
	set("coor/x", -109890);
	set("coor/y", -55000);
	set("coor/z", 300);
	setup();
	"/clone/board/xuedao_b"->foo();
}

void init()
{
	add_action("do_watch", "watch");
	add_action("do_watch", "kan");
	add_action("do_watch", "mianbi");
	add_action("do_watch", "face");
}

int do_watch()
{
	object ob = this_player();
	int lvl = this_player()->query_skill("xue-dao",1);

	if ((int)ob->query_skill("longxiang", 1) < 20)
	{
		message_vision("$N的龙象功不够，看不懂上面刻的是什么。\n",ob);
		return 1;
	}
	if ((int)ob->query_skill("xue-dao", 1) > 50)
	{
		message_vision("$N的血刀刀法早就超越壁上所刻了。\n",ob);
		return 1;
	}
	if((lvl * lvl * lvl) > (int)ob->query("combat_exp"))
	{
		message_vision("$N的实战经验不足，无法领悟壁上内容。\n",ob);
		return 1;
	}
	if (ob->query("jing")<20)
	{
		message_vision("$N太累了，现在无法领悟壁上内容。\n",ob);
		return 1;
	}
	message_vision("$N面对着壁上图案揣摩良久，似有所悟。\n",ob);
	ob->improve_skill("xue-dao", random(ob->query("int")));
	ob->receive_damage("jing", 20);
	return 1;
}
