// Room: /d/wudujiao/shanlu2.c

inherit ROOM;

void create()
{
        set("short", "上山小路");
        set("long", @LONG
这是一条上山的小路，脚下是青石砌成的台阶，湿漉漉的长
满了青苔，四周全是茂密的竹林。远处传来一阵悠扬的山歌声。
LONG
        );
        set("outdoors", "wudujiao");
	set("no_clean_up", 0);
        set("exits", ([
                "southup"   : __DIR__"shanlu3",
                "northdown" : __DIR__"xiaolu",
        ]));

	set("coor/x", -44000);
	set("coor/y", -78110);
	set("coor/z", 10);
	setup();
        replace_program(ROOM);
}