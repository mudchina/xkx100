// garden.c
// Last Modified by winder on Aug. 1 2002

inherit ROOM;
void create()
{
	set("short","花园");
	set("long",@LONG
这是一个园子，庭院清幽，异种花卉甚是不少。百花争放，山石古
拙，杨柳垂清，苍松翠竹，景致煞是宜人。清澈的溪流旁耸立着一座小
亭子，潺潺溪水向西南流去。东面通往有所不为轩，北面是一条长廊，
西边小屋传出阵阵香味，引得你真想去看看。
LONG);
	set("exits",([
		"east"      : __DIR__"buwei1",
		"west"      : __DIR__"chufang",
		"north"     : __DIR__"changlang",
		"south"     : __DIR__"shufang",
		"southwest" : __DIR__"houyuan",
	]));
	set("outdoors", "huashan");
	set("no_clean_up", 0);
	set("coor/x", -870);
	set("coor/y", 220);
	set("coor/z", 120);
	setup();
	replace_program(ROOM);
}
 
