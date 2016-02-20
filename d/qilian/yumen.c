// Room: /d/qilian/yumen.c
// Winder 2000/09/05 

inherit ROOM;

void create()
{
	set("short", "玉门");
	set("long", @LONG
这里是西北的一处调兵站，北对蒙古，西卫青海，尤其是在汉代，
玉门是中原和西域间的一大要塞。北方是哈拉湖，西方是玉门关。
LONG );
	set("outdoors", "qilian");
	set("no_clean_up", 0);
	set("exits", ([
		"southwest" : "/d/xingxiu/jiayuguan",
		"north"     : __DIR__"halahu",
	]));
	set("coor/x", -17000);
	set("coor/y", 1000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}