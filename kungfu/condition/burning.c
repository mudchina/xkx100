// burning.c

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
        int count;
        if (me->query("nuqi") < 200)
        {
                if (! me->query_temp("burning_up"))
                        return 0;

                tell_object(me, "你的心情渐渐的平息了。\n");
                me->set("nuqi",0);
                count = me->query_temp("burning_up");
                me->add_temp("apply/attack", -count);
                me->delete_temp("burning_up");
                return 0;
        }
        me->add("nuqi",-200);
	return 1;
}
