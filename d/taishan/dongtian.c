// Room: /d/taishan/dongtian.c
// Last Modified by Winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "东天门");
	set("long", @LONG
日观峰东边为东天门，双石如门，是岱顶的东面出口。往东为伏虎
门，峡口陡险。下为鹰愁涧，水东北流，入洗鹤湾。涧东岸北崖古洞深
敞，名清静石屋，元初女道冠孙清静曾在此修真。此处川林僻旷，尘迹
罕至，俗呼仙人场。其北为空明山，中穴通明，午时日光穿照。 
LONG );
	set("exits", ([
		"west" : __DIR__"riguanroad2",
	]));
	set("objects", ([
		CLASS_D("taishan")+"/yuyinzi" : 1,
	]));
	set("outdoors", "taishan");
	set("coor/x", 410);
	set("coor/y", 770);
	set("coor/z", 190);
	setup();
	replace_program(ROOM);
}
