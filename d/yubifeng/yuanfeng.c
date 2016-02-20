// /yubifeng/yuanfeng.c
// Last modified by winder 2003.9.2

inherit ROOM;

void create()
{
	set("short", "圆峰");
	set("long", @LONG
一路山脉从东北走向西南，另一路山脉自正南向北，两路山脉相会
之处，便是这座形似圆墩的矮峰。峰覆积雪，映日生辉。
LONG );
	set("exits", ([
		"north"   : __DIR__"xiaolu3",
		"southup" : __DIR__"yuanfengding",
	]));
	set("no_clean_up", 0);
	set("outdoors", "yubifeng");
	set("coor/x", 6100);
	set("coor/y", 5130);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
