// Room: /d/luoyang/lvzuan.c
// Last modified by winder 2002.11.11

inherit  ROOM;

void  create  ()
{
	set("short",  "吕祖庵");
	set("long",  @LONG
吕祖庵又叫吕祖庙，背依邙岭坡，面临深壑，壑内为清清流水。庵
红垣绿槐琉璃房，小巧玲珑，从崖下仰望，如见天空仙境。吕祖庵初为
茶庵，是行人饮茶歇脚之所。后改为道教场所。因庵中道人属全真派，
故香火敬起全真派“五祖”之一的吕洞宾，因施茶性质未变，且庙宇规
模较小，故仍称“吕祖庵”，亦称“纯阳洞”。 
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"southwest" : __DIR__"mangshan",
	]));
	set("outdoors", "luoyang");
	set("no_clean_up", 0);
	set("coor/x", -490);
	set("coor/y", 60);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
