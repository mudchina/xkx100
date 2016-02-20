//Room: /d/city/shuyuan3.c 
string look_table();

#define STORY_TOC "/doc/book/toc"
#define STORY_DIR "/doc/book/"
inherit ROOM;

void create()
{
	set("short", "射雕院");
	set("long", @LONG
这是一间轩敞明净的大屋子，正中一张大书桌 (table)，上面摞了
几叠书。这里收藏了武侠大师金庸先生的主要作品，所有惊心动魄、婉
约深情的故事，由大师的生花妙笔娓娓道来。许多成名后的大侠时常来
这里走走、看看，回味自己漫长的江湖岁月中那些弥足珍贵的感受，以
自己坎坷的刀剑生涯印证大师的手笔，并写下自己走上江湖之路。夜深
人静时，如果您仍辗转难眠，不妨翻翻 (fan)这些书。楼下是飞雪堂，
收藏侠客行早期玩家的作品。
LONG);
	set("item_desc", ([
	    "table" : (: look_table :),
	]));
	set("exits", ([
	    "down" : __DIR__"shuyuan2",
	]));
	set("objects", ([
	    __DIR__"player/aiwoaini" : 1,
	    __DIR__"player/autodami" : 1,
	    __DIR__"player/august" : 1,
	    __DIR__"player/batwing" : 1,
	    __DIR__"player/karice" : 1,
	    __DIR__"player/piaoxue" : 1,
	    __DIR__"player/qianqiu" : 1,
	    __DIR__"player/tiji" : 1,
	    __DIR__"player/welcome" : 1,
	    __DIR__"player/wpp" : 1,
	    __DIR__"player/wrong" : 1,
	    __DIR__"player/yzjiang" : 1,
	]));
	set("no_fight", 1);
	set("coor/x", 20);
	set("coor/y", 32);
	set("coor/z", 30);
	setup();
}

void init()
{
	add_action("do_fan", "fan");
}

string look_table()
{
	this_player()->start_more(read_file(STORY_TOC));
	return "\n";
}

int do_fan(string arg)
{
	object me=this_player();
	if (arg == "" || file_size(STORY_DIR + arg) <= 0)
		return notify_fail("我们没有这本书。\n");

	log_file("LIBRARY", sprintf("%s read %s.\n", me->query("name"), arg));
	me->start_more(read_file(STORY_DIR + arg));
	return 1;
}
