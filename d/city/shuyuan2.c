//Room: /d/city/shuyuan2.c

string look_shelf();

#define STORY_TOC "/doc/legend/toc"
#define STORY_DIR "/doc/legend/"
inherit ROOM;

void create()
{
	set("short", "飞雪堂");
	set("long", @LONG
这是侠客行玩家们闲暇时喜欢逗留的地方。这里窗明几净，一尘不
染。壁上的书架(shelf) 堆满侠客行的先贤们的文选，记录了侠客行的
风风雨雨和无数或凄婉深情或粗豪奔放的传说，虽然那些日子已经很遥
远，却难以磨灭。你可以阅读(read)到这些古老的故事。楼上是射雕院，
收藏有金庸大师的主要作品。
LONG);
	set("item_desc", ([
		"shelf" : (: look_shelf :),
	]));
	set("no_fight", "1");
	set("no_beg", "1");
	set("no_steal", "1");
	set("no_sleep_room", "1");
	set("no_clean_up", 0);

	set("exits", ([
		"down" : __DIR__"shuyuan1",
		"up"   : __DIR__"shuyuan3",
	]));
	set("objects", ([
		__DIR__"obj/wizboard" : 1,
	]));
	set("coor/x", 20);
	set("coor/y", 32);
	set("coor/z", 20);
	setup();
	"/clone/board/shuyuan_b"->foo();
}

void init()
{
	add_action("do_read", "read");
}

string look_shelf()
{
	this_player()->start_more(read_file(STORY_TOC));
	return "\n";
}

int do_read(string arg)
{
	object me=this_player();
	if (arg == "" || file_size(STORY_DIR + arg) <= 0)
		return notify_fail("我们没有这本书。\n");

	log_file("LIBRARY", sprintf("%s read %s.\n", me->query("name"), arg));
	me->start_more(read_file(STORY_DIR + arg));
	return 1;
}
