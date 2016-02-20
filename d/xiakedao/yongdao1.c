// yongdao1.c 甬道


inherit ROOM;

void create()
{
        set("short", "甬道");
        set("long", @LONG
这是一条长长的甬道，两边点着油灯，光线虽暗，却也可辨道
路，外面隐约能听见瀑布的隆隆水声，洞口水花飞溅，地面甚是湿
润。
LONG );
        set("exits", ([
               "south" : __DIR__"yongdao2",
               "out" : __DIR__"pubu",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -3100);
	set("coor/y", -22060);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}