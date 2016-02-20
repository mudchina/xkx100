// Room: /d/tiezhang/mzfeng.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "拇指峰");
	set("long", @LONG
拇指峰是铁掌五峰中最为低矮的一峰，名为峰，实则只是一座较高
的石山罢了。峰顶到处是又大又圆的岩石，在日晒雨淋下，被风蚀得十
分光滑。在岩石的缝隙中，长出许多松树，其中一棵尤其引人注目。这
棵松名为并蒂松(song)，乃同根而生，于距地一米高处，忽分为二。这
两根树干同粗同高，均长得高大挺拔，枝叶茂盛，尤如兄弟一般，因此
又名兄弟松。
LONG	);
	set("exits", ([ /* sizeof() == 1 */
		"southdown" : __DIR__"sslu3",
	]));
	set("item_desc", ([ 
		"song" : "这棵松树能长得如此奇特，必蕴涵了天地日月之精华。\n",
	]));
	set("outdoors", "tiezhang");
	set("no_clean_up", 0);
	set("coor/x", -2010);
	set("coor/y", -1900);
	set("coor/z", 90);
	setup();
}

void init()
{
	add_action("do_caiqi", "caiqi");
}

int do_caiqi(string arg)
{
	mapping fam;
	object me = this_player();

	if (!living(me)) return 0;
	if ( !living(this_player()) || arg != "song" )
	{
		message_vision("你想干什么？\n",me);
		return 1;
	}

	if (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "铁掌帮")
		return notify_fail("你非本帮弟子，不能在此练功！\n");

	if ((int)me->query_skill("force",1)>100)
		return notify_fail("你的内功太高了，已经不能从树中采气了！\n");

	if ((int)me->query_skill("force", 1) < 30 )
		return notify_fail("你的内功太低了，还不能从树中采气！\n");

	if((int)me->query("jing")<20)
	{
		me->receive_damage("jing",10);
		write("你忽然觉得头痛欲裂，无法控制体内的真气！\n");
		me->unconcious();
		return 1;
	}

	me->receive_damage("jing", random(40));
	message_vision("$N双手呈环状，虚抱住一只树干，缓缓吐呐练功。\n", me);
	me->improve_skill("force", me->query("int"));
	return 1;
}
