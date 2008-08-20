#ifndef __NYMBLE_TICKET_WRAP_H__

#include "ruby.h"
#include "nymble_wrap_util.h"
#include "nymble_complaint_wrap.h"
#include "nymble_ticket.h"

extern VALUE rb_cTicket;

VALUE rb_ticket_complain(VALUE rb_self, VALUE rb_time_period);
VALUE rb_ticket_unmarshal(VALUE rb_self, VALUE rb_bytes);
VALUE rb_ticket_marshal(VALUE rb_self);

void rb_ticket_delete(Nymble::Ticket* ticket);

#endif