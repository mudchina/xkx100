// Room:  /d/luoyang/longmen1.c
// Last modified by winder 2002.11.11

inherit  ROOM;

void  create  ()
{
	set("short",  "龙门山色");
	set("long",  @LONG
这里因伊水东西两岸之香山和龙门山夹峙，形若门阙，故古称“伊
阙”，隋唐以后，习称龙门。是进出洛阳的南面雄关。伊水流经其中，
宛如一条长龙穿门而过，通称“龙门”。白居易曾说“洛阳西郊山水之
胜，龙门首焉”，因而“龙门山色”很早被誉为洛阳八大景之首。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"south"  :  __DIR__"road3",
		"north"  :  __DIR__"road4",
		"west"   :  __DIR__"pingquan",
		"eastup" :  __DIR__"longmen",
	]));
	set("outdoors", "luoyang");
	set("no_clean_up", 0);
	set("coor/x", -500);
	set("coor/y", -45);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
