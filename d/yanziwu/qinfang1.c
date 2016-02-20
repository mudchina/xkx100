//ROOM: /d/yanziwu/qinfang1.c

inherit ROOM;

void create()
{
	set("short", "沁芳阁");
	set("long",@LONG
这里是供慕容世家的仆人小憩的地方，三面临水。微风拂过，送来
缕缕的荷花叶香，沁人心脾，沁芳阁因此而名。一架墨绿色的竹梯通向
楼上的休息室。
LONG );
	set("exits", ([
		"east"  : __DIR__"yimen",
		"up"    : __DIR__"qinfang2",
	]));
	set("no_clean_up", 0);
	set("coor/x", 810);
	set("coor/y", -1530);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}