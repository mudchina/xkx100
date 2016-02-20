// midao5.c 密道

inherit ROOM;

void create()
{
	set("short", "秘密通道");
	set("long", @LONG
这是一个石室，隐约可以感觉到四周是冰冷而坚硬的石壁，地
上和角落都是灰尘，大概好久没人来过了。
LONG );

	set("exits", ([
	       "east" : __DIR__"midao4",
	       "out"  : __DIR__"neiting",
	]));
	set("objects", ([
//	       NOSTRUM_DIR"binghuojiu" : 1,
	]));
	set("no_clean_up", 0);
	set("coor/x", -3090);
	set("coor/y", -25000);
	set("coor/z", -20);
	setup();
}

int valid_leave(object me,string dir)
{
	if(dir=="out")
		tell_object(me,"你走出了秘密通道，神秘地出现在内厅之中。\n");
	return ::valid_leave(me,dir);
}
