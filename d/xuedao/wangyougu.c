// wangyougu.c
// Modified by Java Apr.27 1998

inherit ROOM;
void create()
{
        set("short","忘忧谷");
        set("long",@LONG
这里乃是大轮寺外一处僻静所在，四下绝无人迹。前前後後，大大
小小几百座佛塔，被白得耀眼的雪被披盖着。银白色的山野、雪地里闪
耀着红色和蓝色的光带，五彩缤纷，迷宫一样的琼楼仙阁在你眼前出现。
南面一条小径不知通往何处。
LONG );
        set("exits",([
                "south"   : __DIR__"sroad8",
                "southup" : __DIR__"sroad9",
        ]));
        set("objects", ([
                __DIR__"npc/zhuoma" :1,
                __DIR__"npc/yangzong" :1,
        ]));
        set("outdoors", "xueshan");
        set("no_clean_up", 0);
	set("coor/x", -110000);
	set("coor/y", -50000);
	set("coor/z", 200);
	setup();
        replace_program(ROOM);
}