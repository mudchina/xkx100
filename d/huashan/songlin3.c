// Room: /d/huashan/songlin3.c
// Last Modified by winder on Aug. 1 2002

inherit ROOM;

void create()
{	
	int dir1,dir2,dir3,dir4;
	dir1=random(4)+1;
	dir2=random(4)+1;
	dir3=random(4)+1;
	dir4=random(4)+1;
	while (dir1!=4 && dir2!=4 && dir3!=4 && dir4!=4)	
	{	
		dir1=random(4)+1;
		dir2=random(4)+1;
		dir3=random(4)+1;		
		dir4=random(4)+1;		
	}
	set("short", "松树林");
	set("long", @LONG
这是一片松树林。几丈高的松树密密麻麻，遮得不见天日。地上落
满松针，有不知名的野兔偷偷逃过。四周一片寂静。
LONG );
	set("exits", ([
		"east"  : __DIR__"songlin"+dir1,
		"west"  : __DIR__"songlin"+dir2,
		"south" : __DIR__"songlin"+dir3,
		"north" : __DIR__"songlin"+dir4,
	]));
	set("objects", ([
		"/clone/medicine/vegetable/gouzhizi" : random(2),
	]));
	set("no_clean_up", 0);
	set("outdoors", "huashan");
	set("coor/x", -870);
	set("coor/y", 240);
	set("coor/z", 120);
	setup();
	replace_program(ROOM);
}
