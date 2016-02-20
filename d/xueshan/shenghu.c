//      shenghu.c 圣湖

inherit ROOM;

void create()
{
        set("short","圣湖");
        set("long",@LONG
眼前就是著名的圣湖，碧蓝的湖面倒影着蓝天和白云，浩淼的水面
让人心旷神怡。远处金碧辉煌的雪山寺清晰可见，再远处是几座延绵的
大雪山，其中最高大的是神山，相传山中有神仙居住。雪山中融化的雪
水都汇入湖中。
LONG );
        set("resource/water",1);
	set("outdoors", "xueshan");
        set("exits",([
                "south" : __DIR__"tulu3",
                "east"  : __DIR__"hubian1",
		"west"  : "/d/npc/m_weapon/liangunshi",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -30020);
	set("coor/y", -8010);
	set("coor/z", 10);
	setup();
        replace_program(ROOM);
}
