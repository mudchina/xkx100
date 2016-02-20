// hubian.c
// Modified by Winder June.25 2000

inherit ROOM;

void create()
{
	set("short", "湖边");
	set("long", @LONG
这个就是谷底的大湖，湖水一平入镜，月光映入湖中，湖心也是一
轮皎洁的圆月。湖畔还生着一丛丛的各式各样的茶花。在月光下摇曳生
姿。此湖呈椭圆形状，大部分隐入了花树丛中。东南西北四面全是岩石
(stone) 和悬崖(xuanya)，但是悬崖十分陡峭，即使是绝顶的高手，也
无法攀缘而上。
LONG );
	set ("item_desc", ([
		"stone" : "四面都是岩石。。。。不过，好象有一块有点与众不同。\n"
	])  ) ;
	set("exits", ([ /* sizeof() == 2 */
		"east" : __DIR__"gudi",
	]));
	set("objects", ([
		__DIR__"obj/chahua1" : 1,
		__DIR__"obj/chahua2" : 1,
	]));
	set("outdoors", "wuliang" );
	set("coor/x", -50020);
	set("coor/y", -21060);
	set("coor/z", -40);
	setup();
}

void init()
{
	add_action("do_push","push");
	add_action("do_zuan",({"zuan","enter"}));
}

int do_push(string arg)
{
	object me;
	me = this_player();
	if (!arg||arg!="stone") return 0;
	write("你运力双臂，双手扶着一块岩石，大喝一声：“动！”\n");
       if(random((int)me->query("kar")) < 10 )
		{
                write("岩石晃动了一下，但是一晃即回。\n");
		return 1;
		};
	write("岩石缓缓转动，只转到一半，便见岩石后露出一个三尺来高的洞穴(hole)。\n");
	me->set_temp("marks/push",1);
	return 1;
}

int do_zuan(string arg)
{
	object me;
	me = this_player();
	if (!me->query_temp("marks/push")) return 0;
	if ( arg != "hole") return 0;
	message_vision("$N大喜之下，也没去考虑洞中有无危险，便一闪身钻进了山洞里。\n", me);
	me->move(__DIR__"yandong");
	return 1;
}

int valid_leave(object me, string dir)
{
	if (me->query_temp("marks/push") ) me->delete_temp("marks/push");
	return ::valid_leave();
}