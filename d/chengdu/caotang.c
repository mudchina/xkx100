// Room: /d/chengdu/caotang.c
// Modifyed by Sir on Dec. 4 2001
// Last Modifyed by Winder on Dec. 24 2001

inherit ROOM;
string look_gaoshi();
void create()
{
	set("short", "杜甫草堂");
	set("long", @LONG
这里是杜甫流寓成都的故居。草堂里流水回萦，小桥勾连，竹树
掩映，显得既庄严肃穆，古朴典雅，又不失幽深静谧，秀丽清朗。
LONG );
        set("outdoors", "chengdu");
	set("exits", ([
		"south" : __DIR__"baihuatan",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8090);
	set("coor/y", -2970);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
