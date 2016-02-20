// Room: /d/yueyang/dongtingmiao2.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "洞庭庙寝殿");
	set("long", @LONG
寝殿在洞庭庙主殿后面。寝殿为柳毅和小龙女并排坐像，大殿为单
檐歇山式建筑。柳毅在洞庭湖畔为平民百姓做了很多好事，人们为了纪
念他，便在君山筑起洞庭庙，塑起柳毅和龙女像。
LONG );
	set("no_clean_up", 0);
	set("exits", ([
		"south" : __DIR__"dongtingmiao1",
	]));
	set("coor/x", -1660);
	set("coor/y", 2360);
	set("coor/z", -10);
	setup();
	replace_program(ROOM);
}
