//      hubian2.c 湖边小路

inherit ROOM;

void create()
{
        set("short","湖边小路");
        set("long",@LONG
这是圣湖边的小路。长草越径，虫鸣阵阵，偶尔有白色水禽掠湖点
水，激起圈圈涟漪。
LONG );
        set("outdoors","xueshan");
        set("exits",([
                "northeast" : __DIR__"hubian3",
                "west" : __DIR__"hubian1",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -30000);
	set("coor/y", -8010);
	set("coor/z", 10);
	setup();
        replace_program(ROOM);
}
