// Room:  /d/luoyang/mudan.c
// Last modified by winder 2002.11.11

inherit  ROOM;

void  create  ()
{
	set("short",  "牡丹园");
	set("long",  @LONG
自古以来，洛阳墨客骚人云集，因此有“诗都”之称，牡丹香气四
溢，又有“花都”的美誉。宋代诗人欧阳修在《洛阳牡丹记》一文中写
道：“洛阳地脉花最宜，牡丹尤为天下奇。”此句即道出了洛阳的地脉
使牡丹得天独厚。洛阳牡丹以品种繁多，花色奇丽而名扬天下。故有“
洛阳牡丹甲天下”之名句流传于世。这里每年举办洛阳牡丹花会，人潮
涌动，蔚为壮观。据说当年丐帮马副帮主的夫人在此一笑倾国。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"southwest" : __DIR__"road5",
	]));
	set("objects",  ([  /*  sizeof()  ==  2  */
		"/clone/flower/mudan/black1" : random(2),
		"/clone/flower/mudan/black2" : random(2),
		"/clone/flower/mudan/blue1" : random(2),
		"/clone/flower/mudan/blue2" : random(2),
		"/clone/flower/mudan/green1" : random(2),
		"/clone/flower/mudan/green2" : random(2),
		"/clone/flower/mudan/magenta1" : random(2),
		"/clone/flower/mudan/magenta2" : random(2),
		"/clone/flower/mudan/mudan1" : random(2),
		"/clone/flower/mudan/mudan2" : random(2),
		"/clone/flower/mudan/purple1" : random(2),
		"/clone/flower/mudan/purple2" : random(2),
		"/clone/flower/mudan/purple3" : random(2),
		"/clone/flower/mudan/red1" : random(2),
		"/clone/flower/mudan/red2" : random(2),
		"/clone/flower/mudan/red3" : random(2),
		"/clone/flower/mudan/red4" : random(2),
		"/clone/flower/mudan/white1" : random(2),
		"/clone/flower/mudan/white2" : random(2),
		"/clone/flower/mudan/white3" : random(2),
		"/clone/flower/mudan/white4" : random(2),
		"/clone/flower/mudan/yellow1" : random(2),
		"/clone/flower/mudan/yellow2" : random(2),
	]));
	set("outdoors", "luoyang");
	set("no_get_from", 1);
	set("no_clean_up", 0);
	set("coor/x", -490);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
