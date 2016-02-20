// Room: /d/guiyun/shiqiao.c
// Last Modified by winder on Jul. 9 2001

inherit ROOM;

void create()
{
	set("short", "大石桥");
	set("long",@LONG
这是归云庄前的石桥，再向西就进庄了。向庄子里望去，但见楼阁纡连，
竟是好大一座庄院。
LONG );
	set("exits",([
		"north" : __DIR__"damen",
		"east"  : __DIR__"road4",
	]) );
	set("no_clean_up",0);
	set("outdoors", "guiyun");
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "east")
	{
		write("庄前有一个依据九宫算术布成的桃花阵。\n");
		if ((me->query("family/family_name") == "桃花岛" &&
			me->query_skill("qimen-wuxing", 1) > 14) ||
			me->query_skill("qimen-wuxing", 1) > 39)
			write( "由于你平常看惯了这些简易的阵法，所以不用细想，信步就走出了阵！\n");
		else {
			me->set_temp("jiugong_dir", "e");
			me->move(__DIR__"jiugong" + (random(9) + 1));
			return notify_fail("");
		}
	}
	return ::valid_leave(me, dir);
}
