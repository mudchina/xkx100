// Room: /d/wudujiao/caoping.c

inherit ROOM;

void create()
{
        set("short", "卧龙岗上");
        set("long", @LONG
山顶有一大片开阔地，蓝蓝的天上飘着几朵白云，脚下是绿
油油的草地，浅浅的刚好可以盖过脚面,散发着一种诱人的芳香
舒服的人直想躺在上面打滚。前面有几间简陋的竹舍。
LONG
        );
        set("outdoors", "wudujiao");
	set("no_clean_up", 0);
        set("exits", ([
                "south" : __DIR__"zhushe",
                "northdown" : __DIR__"shanlu3",
        ]));

	set("coor/x", -44000);
	set("coor/y", -78130);
	set("coor/z", 30);
	setup();
        replace_program(ROOM);
}