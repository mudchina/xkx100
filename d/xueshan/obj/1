// 13jiasha.c

#include <armor.h>
#include <ansi.h>
inherit CLOTH;
inherit F_UNIQUE;
void create()
{
        set_name(HIW"十三龙象袈裟"NOR, ({ "shisan longxiang", "jiasha", "longxiang jiasha" }));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("jiasha/neili", 0);
                set("long", HIW"这是一件喇嘛穿的袈裟，上面绣着些梵文，看似普通但却是大轮寺开寺始祖终身所穿的袈裟。
可能是因为它长时间被龙象内力笼罩，所以也似乎有了储存内力的功效。你可以试试注入内力(longxiang)。\n"NOR);
                set("material", "silk");
                set("unit", "件");
                set("unique", 1);
                set("value", 100);
                set("wear_msg", HIW"只见$N双手一抖，便把一件隐隐透着紫色光彩的袈裟穿在了身上。\n" NOR);
                set("remove_msg", HIW"$N脱下一件十三龙象袈裟，小心翼翼的放入怀中。\n" NOR);
                set("armor_prop/armor", 500);
                set("treasure",1);
        }
        setup();
}

void init()
{
    add_action("do_add", "longxiang");
}

int do_add(string arg)
{
        int neili;

        object me = this_player();

        if (!living(this_player()))
        return notify_fail("什么？\n");

        if( this_player()->is_busy() )
                return notify_fail("你上一个动作还没有完成。\n");

        if( me->query_skill_mapped("force") == "longxiang" && me->query("neili", 1) < 1000 )
                return notify_fail("你的内力不足，无法注入足够的内力！\n");     

        if( me->query_skill_mapped("force") != "longxiang" && me->query("neili", 1) < 1500 )
                return notify_fail("你的内力不足，无法注入足够的内力！\n");     

        if ( me->is_fighting())
                return notify_fail("战斗中不能将内力注入袈裟。\n");

        if( query("jiasha/neili") > 12)
                return notify_fail("袈裟中已经充满了内力，你再也无法注入了！\n");

        if (me->query_skill_mapped("force") != "longxiang" ) {
        message_vision(CYN"$N潜运内功，努力把内力注入十三龙象袈裟，最后虽然成功但因为不是龙象内力而多花了点力气。\n"NOR, me);
        me->receive_damage("neili", 1000+random(500));
        } else {
        message_vision(MAG"$N脸上泛起一层隐隐的紫气，双手虚按十三龙象袈裟，把龙象内力注入袈裟之中。\n"NOR, me);
        me->receive_damage("neili", 1000);}
        add("jiasha/neili", 1);
        neili = this_object()->query("jiasha/neili", 1);
        if(query("jiasha/neili") >= 13) {
        set_name(MAG"十三龙象袈裟"NOR, ({ "shisan longxiang", "jiasha", "longxiang jiasha" }));
        set("long", MAG"这是一件喇嘛穿的袈裟，上面绣着些梵文，看似普通但却是大轮寺开寺始祖终身所穿的袈裟。
可能是因为它长时间被龙象内力笼罩，所以也似乎有了储存内力的功效。你可以试试注入内力。你可以试试注入内力(longxiang)。
袈裟之上已经注有"+ chinese_number(neili) +"道内力！\n"NOR);}
        else if(query("jiasha/neili") == 11 || query("jiasha/neili") == 12) {
        set_name(HIM"十三龙象袈裟"NOR, ({ "shisan longxiang", "jiasha", "longxiang jiasha" }));
        set("long", HIM"这是一件喇嘛穿的袈裟，上面绣着些梵文，看似普通但却是大轮寺开寺始祖终身所穿的袈裟。
可能是因为它长时间被龙象内力笼罩，所以也似乎有了储存内力的功效。你可以试试注入内力。你可以试试注入内力(longxiang)。
袈裟之上已经注有"+ chinese_number(neili) +"道内力！\n"NOR);}
        else if(query("jiasha/neili") == 9 || query("jiasha/neili") == 10) {
        set_name(BLU"十三龙象袈裟"NOR, ({ "shisan longxiang", "jiasha", "longxiang jiasha" }));
        set("long", BLU"这是一件喇嘛穿的袈裟，上面绣着些梵文，看似普通但却是大轮寺开寺始祖终身所穿的袈裟。
可能是因为它长时间被龙象内力笼罩，所以也似乎有了储存内力的功效。你可以试试注入内力。你可以试试注入内力(longxiang)。
袈裟之上已经注有"+ chinese_number(neili) +"道内力！\n"NOR);}
        else if(query("jiasha/neili") == 7 || query("jiasha/neili") == 8) {
        set_name(HIB"十三龙象袈裟"NOR, ({ "shisan longxiang", "jiasha", "longxiang jiasha" }));
        set("long", HIB"这是一件喇嘛穿的袈裟，上面绣着些梵文，看似普通但却是大轮寺开寺始祖终身所穿的袈裟。
可能是因为它长时间被龙象内力笼罩，所以也似乎有了储存内力的功效。你可以试试注入内力。你可以试试注入内力(longxiang)。
袈裟之上已经注有"+ chinese_number(neili) +"道内力！\n"NOR);}
        else if(query("jiasha/neili") == 5 || query("jiasha/neili") == 6) {
        set_name(HIC"十三龙象袈裟"NOR, ({ "shisan longxiang", "jiasha", "longxiang jiasha" }));
        set("long", HIC"这是一件喇嘛穿的袈裟，上面绣着些梵文，看似普通但却是大轮寺开寺始祖终身所穿的袈裟。
可能是因为它长时间被龙象内力笼罩，所以也似乎有了储存内力的功效。你可以试试注入内力。你可以试试注入内力(longxiang)。
袈裟之上已经注有"+ chinese_number(neili) +"道内力！\n"NOR);}
        else if(query("jiasha/neili") == 3 || query("jiasha/neili") == 4) {
        set_name(CYN"十三龙象袈裟"NOR, ({ "shisan longxiang", "jiasha", "longxiang jiasha" }));
        set("long", CYN"这是一件喇嘛穿的袈裟，上面绣着些梵文，看似普通但却是大轮寺开寺始祖终身所穿的袈裟。
可能是因为它长时间被龙象内力笼罩，所以也似乎有了储存内力的功效。你可以试试注入内力。你可以试试注入内力(longxiang)。
袈裟之上已经注有"+ chinese_number(neili) +"道内力！\n"NOR);}
        else if(query("jiasha/neili") == 1 || query("jiasha/neili") == 2) {
        set_name(HIW"十三龙象袈裟"NOR, ({ "shisan longxiang", "jiasha", "longxiang jiasha" }));
        set("long", HIW"这是一件喇嘛穿的袈裟，上面绣着些梵文，看似普通但却是大轮寺开寺始祖终身所穿的袈裟。
可能是因为它长时间被龙象内力笼罩，所以也似乎有了储存内力的功效。你可以试试注入内力。你可以试试注入内力(longxiang)。
袈裟之上已经注有"+ chinese_number(neili) +"道内力！\n"NOR);}
        return 1;
}

int ob_hit(object ob, object me, int damage)
{
   int neili;
   if( damage < 100 ) return 0;
   if( query("jiasha/neili") > 0 ) {

   if( query("jiasha/neili") == 1 || query("jiasha/neili") == 2 ) {
   message_vision(HIW"十三龙象袈裟突然发出耀眼的光芒，抵挡了$N的部分攻势！\n"NOR, ob,me);}
   else if( query("jiasha/neili") == 3 || query("jiasha/neili") == 4 ) {
   message_vision(CYN"十三龙象袈裟突然发出耀眼的光芒，抵挡了$N的部分攻势！\n"NOR, ob,me);}
   else if( query("jiasha/neili") == 5 || query("jiasha/neili") == 6 ) {
   message_vision(HIC"十三龙象袈裟突然发出耀眼的光芒，抵挡了$N的部分攻势！\n"NOR, ob,me);}
   else if( query("jiasha/neili") == 7 || query("jiasha/neili") == 8 ) {
   message_vision(HIB"十三龙象袈裟突然发出耀眼的光芒，抵挡了$N的部分攻势！\n"NOR, ob,me);}
   else if( query("jiasha/neili") == 9 || query("jiasha/neili") == 10 ) {
   message_vision(BLU"十三龙象袈裟突然发出耀眼的光芒，抵挡了$N的部分攻势！\n"NOR, ob,me);}
   else if( query("jiasha/neili") == 11 || query("jiasha/neili") == 12 ) {
   message_vision(HIM"十三龙象袈裟突然发出耀眼的光芒，抵挡了$N的部分攻势！\n"NOR, ob,me);}
   else message_vision(MAG"十三龙象袈裟突然发出耀眼的光芒，抵挡了$N的部分攻势！\n"NOR, ob,me);

   if( random(2) != 1 ) add("jiasha/neili", -1);
   neili = this_object()->query("jiasha/neili", 1);
        if(query("jiasha/neili") >= 13) {
        set_name(MAG"十三龙象袈裟"NOR, ({ "shisan longxiang", "jiasha", "longxiang jiasha" }));
        set("long", MAG"这是一件喇嘛穿的袈裟，上面绣着些梵文，看似普通但却是大轮寺开寺始祖终身所穿的袈裟。
可能是因为它长时间被龙象内力笼罩，所以也似乎有了储存内力的功效。你可以试试注入内力。你可以试试注入内力(longxiang)。
袈裟之上已经注有"+ chinese_number(neili) +"道内力！\n"NOR);}
        else if(query("jiasha/neili") == 11 || query("jiasha/neili") == 12) {
        set_name(HIM"十三龙象袈裟"NOR, ({ "shisan longxiang", "jiasha", "longxiang jiasha" }));
        set("long", HIM"这是一件喇嘛穿的袈裟，上面绣着些梵文，看似普通但却是大轮寺开寺始祖终身所穿的袈裟。
可能是因为它长时间被龙象内力笼罩，所以也似乎有了储存内力的功效。你可以试试注入内力。你可以试试注入内力(longxiang)。
袈裟之上已经注有"+ chinese_number(neili) +"道内力！\n"NOR);}
        else if(query("jiasha/neili") == 9 || query("jiasha/neili") == 10) {
        set_name(BLU"十三龙象袈裟"NOR, ({ "shisan longxiang", "jiasha", "longxiang jiasha" }));
        set("long", BLU"这是一件喇嘛穿的袈裟，上面绣着些梵文，看似普通但却是大轮寺开寺始祖终身所穿的袈裟。
可能是因为它长时间被龙象内力笼罩，所以也似乎有了储存内力的功效。你可以试试注入内力。你可以试试注入内力(longxiang)。
袈裟之上已经注有"+ chinese_number(neili) +"道内力！\n"NOR);}
        else if(query("jiasha/neili") == 7 || query("jiasha/neili") == 8) {
        set_name(HIB"十三龙象袈裟"NOR, ({ "shisan longxiang", "jiasha", "longxiang jiasha" }));
        set("long", HIB"这是一件喇嘛穿的袈裟，上面绣着些梵文，看似普通但却是大轮寺开寺始祖终身所穿的袈裟。
可能是因为它长时间被龙象内力笼罩，所以也似乎有了储存内力的功效。你可以试试注入内力。你可以试试注入内力(longxiang)。
袈裟之上已经注有"+ chinese_number(neili) +"道内力！\n"NOR);}
        else if(query("jiasha/neili") == 5 || query("jiasha/neili") == 6) {
        set_name(HIC"十三龙象袈裟"NOR, ({ "shisan longxiang", "jiasha", "longxiang jiasha" }));
        set("long", HIC"这是一件喇嘛穿的袈裟，上面绣着些梵文，看似普通但却是大轮寺开寺始祖终身所穿的袈裟。
可能是因为它长时间被龙象内力笼罩，所以也似乎有了储存内力的功效。你可以试试注入内力。你可以试试注入内力(longxiang)。
袈裟之上已经注有"+ chinese_number(neili) +"道内力！\n"NOR);}
        else if(query("jiasha/neili") == 3 || query("jiasha/neili") == 4) {
        set_name(CYN"十三龙象袈裟"NOR, ({ "shisan longxiang", "jiasha", "longxiang jiasha" }));
        set("long", CYN"这是一件喇嘛穿的袈裟，上面绣着些梵文，看似普通但却是大轮寺开寺始祖终身所穿的袈裟。
可能是因为它长时间被龙象内力笼罩，所以也似乎有了储存内力的功效。你可以试试注入内力。你可以试试注入内力(longxiang)。
袈裟之上已经注有"+ chinese_number(neili) +"道内力！\n"NOR);}
        else if(query("jiasha/neili") == 1 || query("jiasha/neili") == 2) {
        set_name(HIW"十三龙象袈裟"NOR, ({ "shisan longxiang", "jiasha", "longxiang jiasha" }));
        set("long", HIW"这是一件喇嘛穿的袈裟，上面绣着些梵文，看似普通但却是大轮寺开寺始祖终身所穿的袈裟。
可能是因为它长时间被龙象内力笼罩，所以也似乎有了储存内力的功效。你可以试试注入内力。你可以试试注入内力(longxiang)。
袈裟之上已经注有"+ chinese_number(neili) +"道内力！\n"NOR);}
        else if(query("jiasha/neili") <= 0) {
        set_name(HIW"十三龙象袈裟"NOR, ({ "shisan longxiang", "jiasha", "longxiang jiasha" }));
        set("long", HIW"这是一件喇嘛穿的袈裟，上面绣着些梵文，看似普通但却是大轮寺开寺始祖终身所穿的袈裟。
可能是因为它长时间被龙象内力笼罩，所以也似乎有了储存内力的功效。你可以试试注入内力。你可以试试注入内力(longxiang)。\n"NOR);}
   return -(300+random(600));
   } else {
   return 0;}
}
