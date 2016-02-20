// Room: /wuliang/shanlu3.c
// Date: Oct.18 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
山路渐渐崎岖难行，侧转一个弯，蜿蜒向上，更是艰险。你抬头
望去，却只见东边山腰里冒起一条条的袅袅青烟，共有十余丛之多，
不知道是甚么意思。
LONG );
        set("outdoors", "wuliang");
	set("no_clean_up", 0);
	set("exits", ([
		"southdown" : __DIR__"shanlu2",
		"eastup"    : __DIR__"shanlu4",
	]));
	set("coor/x", -71000);
	set("coor/y", -79990);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}